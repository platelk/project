(****************************************************************************)
(*                                                                          *)
(*                     assistants.ml in langage_de_module                   *)
(*                     For Epitech's λ Knowledge Unit                       *)
(*                     Made by: David GIRON                                 *)
(*                                                                          *)
(****************************************************************************)


module type ASSISTANT =
  sig

    type t

    val new_assistant : string -> int -> t

    val get_name : t -> string
    val get_promo : t -> int

    val print : t -> unit

  end


module Koala : ASSISTANT =
  struct

    type t = (string * int)

    let new_assistant n p = (n, p)

    let get_name (n, _) = n
    let get_promo (_, p) = p

    let print (n, p) =
      Printf.printf "%s est un Koala de la promo %d\n" n p

  end


module Astek : ASSISTANT =
  struct

    type t = {name : string; promo : int}

    let new_assistant n p = {name = n; promo = p}

    let get_name {name = n; promo = _} = n
    let get_promo {name = _; promo = p} = p

    let print {name = n; promo = p} =
      Printf.printf "%s est un Astek de la promo %d\n" n p

  end
