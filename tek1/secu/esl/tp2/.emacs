;; ajout au PATH-Emacs
(setq load-path (cons "~/.emacs.d/" load-path))

(setq compile-command "make")
(setq show-trailing-whitespace t)
(setq-default show-trailing-whitespace t)

(font-lock-mode t)
(global-font-lock-mode t)
(setq font-lock-maximum-decoration 5)

(set-face-foreground   'font-lock-string-face "Yellow")
(set-face-foreground   'font-lock-comment-face	"OrangeRed")
(set-face-foreground   'font-lock-keyword-face	"Cyan")
(set-face-bold-p       'font-lock-keyword-face t)
(set-face-foreground   'font-lock-type-face	"Wheat")
; (set-face-underline-p  'font-lock-type-face t)
(set-face-foreground   'font-lock-function-name-face	"Blue")
(set-face-bold-p       'font-lock-function-name-face t)
(set-face-foreground   'font-lock-variable-name-face	"Green")
;; reference
; (set-face-foreground   'font-lock-constant-face "White")
; (set-face-background   'font-lock-constant-face "BlueViolet")


(set-terminal-coding-system 'latin-1)
(set-language-environment 'latin-1)
;(set-keyboard-coding-system 'latin-1)

;; Bip a la con
; (setq visible-bell t)
;; Affiche le nom du fichier en haut de la fenetre.
(setq frame-title-format "%b")
;; Affiche le lien entre les parantheses.
(show-paren-mode t)
;; colorise la region entre les deux marques
(transient-mark-mode t)
;; non clignotant.
(setq blink-cursor nil)
;; Indentation par defaut
(setq c-indentation-style "sh-mode")
;; vi ~ style
(setq default-indicate-empty-lines t)

;; Affiche le nombre de colonnes.
(column-number-mode t)
;; Pas de barre de menu.
(menu-bar-mode nil)
;; Pas de barre d'outils.
; (tool-bar-mode nil)

; affichage de l'heure dans la modeline
(display-time)

;; when moving the cursor to the bottom/top of screen, scroll up/down 2 lines
(setq scroll-step 5)
;; when moving page up/down, keep 1 line in common
(setq next-screen-context-lines 5)

;; Une touche DEL fonctionnelle
(and
 window-system
 (functionp 'normal-erase-is-backspace-mode)
 (normal-erase-is-backspace-mode nil))

;; mode Python
;;(autoload 'python-mode "python-mode" "Python editing mode." t)
;; mode PHP
;;(autoload 'php-mode "php-mode" "PHP editing mode." t)

;;(load "ibuffer.el")
;;(global-set-key "\C-x\C-b" 'ibuffer)

;;(load "kill-ring-rotate.el")
;;(global-set-key "\C-x\C-k" 'kill-ring-rotate)

;;(load "shell-toggle-patched.el")
;;(global-set-key "\C-x\C-t" 'shell-toggle)

(global-set-key "\C-c\C-g" 'goto-line)
(global-set-key "\C-c\C-c" 'compile)
(global-set-key [home]    'beginning-of-line)
(global-set-key [end]     'end-of-line)

;; Jeux de claviers
(setq default-input-method 'french-postfix)
(global-set-key "\C-x\C-g" 'toggle-input-method)
(add-hook 'message-mode-hook 'toggle-input-method)

(defun moy-prefered-window-configuration ()
  (interactive)
  (shell-toggle 'nil)
  (shell-toggle 'nil)
  (delete-other-windows)
  (split-window-horizontally)
  (other-window 1)
  (split-window-vertically 24)
  (split-window-vertically)
  (switch-to-buffer "*compilation*")
  (other-window 1)
  (switch-to-buffer "*ansi-term*")
  (other-window 1)
  (ff-find-other-file)
  (other-window -3)
  )

(defun moy-compile-window-configuration ()
  (interactive)
  (shell-toggle 'nil)
  (shell-toggle 'nil)
  (delete-other-windows)
  (split-window-vertically 12)
  (switch-to-buffer "*compilation*")
  (other-window 1)
  )

;;(defun moy-gnus-window ()
;;  (interactive)
;;  (delete-other-windows)
;;  (switch-to-buffer "*Group*")
;;  )

(global-set-key [C-f5] 'moy-prefered-window-configuration)
(global-set-key [C-f6] 'moy-compile-window-configuration)
;;(global-set-key [C-f7] 'moy-gnus-window)

; (server-start)

;; Truc pour emacs display...

; (setq browse-url-generic-program "firefox")
;; Le curseur reste toujours en pos quand on scroll
; (setq scroll-preserve-screen-position t)
; (setq cursor-in-non-selected-windows t)
;; Copie a l'endroit du curseur, pas de la souris
; (setq mouse-yank-at-point t)
