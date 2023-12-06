#lang racket

;; for x in $(for i in {1..198}; do for win in $(cat input4 | cut -f2 -d":" | cut -f1 -d"|" | head -n $i | tail -n 1); do echo $(cat input4 | cut -f2 -d":" | cut -f2 -d"|" | head -n $i | tail -n 1) | tr " " "\n" | grep -o "^$win$"; done | wc -l; done); do echo -n "$x "; done

(define ls (list 8 7 6 7 4 7 2 6 0 3 2 3 2 0 0 10 10 10 10 10 10 10 4 7 10 0 3 2 6 6 2 6 6 4 2 3 2 1 1 0 10 5 4 10 7 10 1 10 2 8 0 7 4 8 0 3 2 4 1 2 1 0 0 10 9 6 0 7 2 3 8 4 3 3 2 2 2 1 0 10 10 10 10 8 10 7 7 9 3 8 0 2 3 4 3 5 1 1 2 1 0 2 1 0 1 1 10 10 6 5 6 1 7 2 5 5 4 1 1 0 0 10 10 7 3 4 8 8 0 9 4 7 8 1 3 7 0 6 4 0 1 0 0 0 10 0 2 0 2 9 9 5 2 8 7 5 6 0 0 2 0 0 1 0 10 3 4 5 9 1 7 2 10 8 2 6 6 3 4 3 2 1 0 0 3 8 0 0 8 0 0 3 5 3 1 2 1 0 ))

(define (rec idx)
  (let ([result (list-ref ls idx)]
	[sum 1])
    (for ([index (in-range (+ idx 1) (+ idx (+ result 1)))])
	 (set! sum (+ sum (rec index))))
    sum))

(foldl (lambda (x v) (+ v (rec x))) 0 (for/list ([i (in-range 0 198)])i))
