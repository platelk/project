(****************************************************************************)
(*                                                                          *)
(*                      main.ml in langage_de_modules                       *)
(*                      For Epitech's λ Knowledge Unit                      *)
(*                      Made by: David GIRON                                *)
(*                                                                          *)
(****************************************************************************)



let main () =
  let zaz = Assistants.Koala.new_assistant "Zaz" 2011
  and guillaume = Assistants.Astek.new_assistant "Guillaume" 2012 in
    begin
      Assistants.Koala.print zaz;
      Assistants.Astek.print guillaume
    end


(****************************************************************************)
let _ = main ()
