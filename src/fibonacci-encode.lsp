;; File : fibonacci-encode.lsp
;; Author : Andrew Bragg
;; Purpose : HW 3

(defun fib (n)
  "Tail recursive fib"
  (labels ((_fib (n a b)
    (if (= n 0) a
      (_fib (- n 1) b (+ a b)))))
  (_fib n 0 1)))

(defun getPrevFibIndex (n)
  "Return the first fibonacci number below the provided value"
  (funcall (lambda (idx)
  (loop do
    (incf idx)
    while (> n (fib idx)))
    (format t "~%~D" (- idx 1))

  (fib (- idx 1))) 0))


(defun square(n)
  "Square and return the provided argument"
  (* n n))

(defun cube(n)
  "Cube and return the provided argument"
  (* n n n))


(defun getNum (k)
  (if (> k 1)
   (getNum (- k (getPrevFibIndex k)))
  ))

;; Main
(defun fibEncode(n)
  (getNum n)
(values))

(format t "encode 6543")
(fibEncode 6543)

(format t "encode 6543 squared")
(fibEncode (square 6543))

(format t "encode 6543 cubed")
(fibEncode (cube 6543))

(quit)


19 17 15 12 6 3
