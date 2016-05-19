;; File : fact.lisp
;; Author : Sandeep Koranne (C) 2016. All rights reserved
;; Purpose : Example code for CST223
#| This is a way to do block comments in Common Lisp
They can span multiple lines
|#
#+nil(setf *debug* nil) ; to toggle some S-exp code
(defun fact (n)
  "Compute the factorial of non-negative integer" ; doc-string
  (if (< n 2) 1
    (* n (fact (1- n)))))
  (defun main(n)
    (format t "~%----------------")
    (dotimes (i n)
      (format t "~%~D! = ~10D" i (fact i)))
    (format t "~%----------------~%")
    (values)) ; to return void value from function
(main 10)
(quit) ; to quit
