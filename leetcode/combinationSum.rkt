#lang racket
(define (combination-sum candidates target)
  (local [;;list 
          (define (solve n chosen ic)
            (cond [(< n target) (solve-loc ic chosen n)]
                  [(= n target) (list chosen)]
                  [(> n target) empty]
                  [else false]))
          ;;list
          (define (solve-loc c chosen at)
            (cond [(empty? c) empty]
                  [else
                   (local [(define try (solve (+ (first c) at) (cons (first c) chosen) c))]
                     (if (not (empty? try))
                         (append try (solve-loc (rest c) chosen at))
                         (solve-loc (rest c) chosen at)))]))]
    (solve-loc candidates empty 0)))

(combination-sum (list 2 3 6 7) 7)