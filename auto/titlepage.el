(TeX-add-style-hook
 "titlepage"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("oci" "12pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8")))
   (TeX-run-style-hooks
    "latex2e"
    "oci"
    "oci12"
    "graphicx"
    "enumitem"
    "inputenc"))
 :latex)

