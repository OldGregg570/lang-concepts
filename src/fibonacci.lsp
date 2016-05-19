;; File : fibonacci.lsp
;; Author : Andrew Bragg
;; Purpose : HW 3
(defun xfib (n)
  "Compute the nth fibonacci number" ; doc-string
  (if (< n 2) n
    (+ (fib (- n 1)) (fib (- n 2)))))


(defun fib (n)
  "Tail recursive fib"
  (labels ((_fib (n a b)
    (if (= n 0) a
      (_fib (- n 1) b (+ a b)))))
  (_fib n 0 1)))


;; Main
(defun main(n)
  (format t "~%----------------")
  (dotimes (i n)
    (format t "~%~D! = ~10D" i (fib i)))
  (format t "~%----------------~%")
  (values)) ; to return void value from function
(main 20)
(quit)
