(****************************************************************************)
(*                                                                          *)
(*                         main.ml in abstracts_types                       *)
(*                         For Epitech's λ Knowledge Unit                   *)
(*                         Made by: David GIRON                             *)
(*                                                                          *)
(****************************************************************************)



let main () =
  let thor = Koala.create "Thor" 27 2009 true in
  begin
    Koala.print thor                                        (* Ok !!!        *)
    (*Koala.print ("Thor", 27, 2009, true)                  (* Fail !!! *)   *)
  end


(****************************************************************************)
let _ = main ()
