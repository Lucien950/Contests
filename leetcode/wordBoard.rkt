#lang racket
(require test-engine/racket-tests)
 (require racket/set)

(struct pos (x y))
(define/contract (exist board word)
  (-> (listof (listof char?)) string? boolean?)
  (local [(define height (length board))
          (define width (length (first board)))

          (define (is-in-list list value)
            (cond
              [(empty? list) false]
              [(and (= (pos-x (first list)) (pos-x value))
                    (= (pos-y (first list)) (pos-y value))) true]
              [else (is-in-list (rest list) value)]))
          (define (inrange p)
            (and (<= 0 (pos-x p) (- width 1))
                 (<= 0 (pos-y p) (- height 1))))
          (define (next-locs p visited)
            (filter inrange
                    (local [(define x (pos-x p))
                            (define y (pos-y p))]
                      (list (pos (+ x 1) y)
                            (pos (- x 1) y)
                            (pos x (+ y 1))
                            (pos x (- y 1))))))
          
          (define (solve word p visited)
            (cond [(= (string-length word) 0) true]
                  [(not (char=?
                         (string-ref word 0)
                         (list-ref (list-ref board (pos-y p))
                                   (pos-x p)))) false]
                  [(is-in-list visited p) false]
                  [else
                   (local [(define nextLocs (next-locs p visited))]
                     (solve-lopos (substring word 1) nextLocs (cons p visited)))]))
          
          (define (solve-lopos word nextlocs visited)
            (cond [(= (string-length word) 0) true]
                  [(empty? nextlocs) false]
                  [else
                   (local [(define try (solve word (first nextlocs) visited))]
                     (if try true
                         (solve-lopos word (rest nextlocs) visited)))]))

          (define (solve-init p)
            (if (= (pos-y p) height) false
                (local [(define try (solve word p empty))]
                  (if try true
                      (if (= (pos-x p) (- width 1))
                          (solve-init (pos 0 (+ (pos-y p) 1)))
                          (solve-init (pos (+ (pos-x p) 1) (pos-y p))))))))

          (define boardset (foldr set-union (set) (map list->set board)))
          (define charset (list->set (string->list word)))]
    (and (subset? charset boardset) (solve-init (pos 0 0)))))

(define B1 (list (list #\A #\B #\C #\E) (list #\S #\F #\C #\S) (list #\A #\D #\E #\E)))
(exist B1 "ABCCED")

(define B2 (list (list #\A #\B #\C #\E)
                 (list #\S #\F #\C #\S) (list #\A #\D #\E #\E)))
(exist B2 "SEE")

(define B3 (list (list #\A #\B #\C #\E)
                 (list #\S #\F #\C #\S) (list #\A #\D #\E #\E)))
(exist B3 "ABCB")


(exist (list (list #\a)) "a")