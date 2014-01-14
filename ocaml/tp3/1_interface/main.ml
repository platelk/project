(***************************************************************************)
(*                                                                         *)
(*                         main.ml in interface                            *)
(*                         For Epitech's λ Knowledge Unit                  *)
(*                         Made by: David GIRON                            *)
(*                                                                         *)
(***************************************************************************)



let main () =
  let thor = Koala.create "Thor" 27 2009 true in
  begin
    Koala.print thor;                    (* koala                          *)
    Koala.print ("Thor", 27, 2009, true) (*(name * age * promo * graduated)*)
  end


(***************************************************************************)
let _ = main ()
