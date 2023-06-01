#lang racket

(struct tree-node (val left right))

(define/contract (right-side-view root)
  (-> (or/c tree-node? #f) (listof exact-integer?))
  (local [(define (carr a b)
            (cond [(empty? a) b]
                  [(empty? b) a]
                  [else (cons (first a) (carr (rest a) (rest b)))]))
          (define (fn-for-x x)
            (cond [(false? x) empty]
                  [else
                   (cons (tree-node-val x)
                         (carr
                          (fn-for-x (tree-node-right x))
                          (fn-for-x (tree-node-left x))))]))]
    (fn-for-x root)))


(define T1 (tree-node 1 false (tree-node 3 false false)))

(right-side-view T1)