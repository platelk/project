#use "my_list.ml"

let convert l =
  let rec aux l ml = match l with
    | [] -> ml
    | head::rest -> aux rest ( Item ( head, ml ) )
  in aux ( List.rev l ) Empty
;;

let la = [1;2;3];;
let lb = ["toto";"foo";"bar";"alexis";"il";"est";"trop";"fort"];;
let lc = [42;21;84;-1;5;1;4;5;78;54;3;98;6;5;968;2;68;26;45;-5;4;4;54];;
let l1 = [1;2;3;4;5;6];;
let l2 = [11];;
let l3 = [99;98;97];;
let ll = [l1;l2;l3];;
let lf = [("hugo", 21); ("ronan", 19); ("alexis", 20)];;

let mla = convert la;;
let mlb = convert lb;;
let mlc = convert lc;;
let ml1 = convert l1;;
let ml2 = convert l2;;
let ml3 = convert l3;;
let mll = Item (ml1, Item (ml2, Item (ml3, Empty ) ) );;
let mlf = convert lf;;

print_string "Test length :\n";;
List.length lc;;
length mlc;;

print_string "Test HD :\n";;
List.hd lb;;
hd mlb;;

print_string "Test TL :\n";;
List.tl la;;
tl mla;;

print_string "Test nth :\n";;
List.nth lb 3;;
nth mlb 3;;

print_string "Test rev :\n";;
List.rev la;;
rev mla;;

print_string "Test append :\n";;
List.append lc la;;
append mlc mla;;

print_string "Test rev_append :\n";;
List.rev_append lc la;;
rev_append mlc mla;;

print_string "Test concat :\n";;
List.concat ll;;
concat mll;;

print_string "Test flatten :\n";;
List.flatten ll;;
flatten mll;;

print_string "Test iter :\n";;
let print a  = print_endline ( string_of_int a );;
List.iter print la;;
iter print mla;;


print_string "Test map :\n";;
let paire a = if ( a mod 2 ) = 0 then true else false;;
List.map paire la;;
map paire mla;;

print_string "Test fold_left :\n";;
let add x y = x + y;;
List.fold_left add 42 lc;;
fold_left add 42 mlc;;

print_string "Test for_all :\n";;
let pos x = if x < 0 then false else true;;
List.for_all pos lc;;
for_all pos mlc;;
List.for_all pos la;;
for_all pos mla;;

print_string "Test exists :\n";;
let neg x = if x < 0 then true else false;;
List.exists neg la;;
exists neg mla;;
List.exists neg lc;;
exists neg mlc;;

print_string "Test mem :\n";;
List.mem 42 lc;;
mem 42 mlc;;
List.mem 42 la;;
mem 42 mla;;

print_string "Test memq :\n";;
List.memq 42 lc;;
memq 42 mlc;;
List.memq 42 la;;
memq 42 mla;;

print_string "Test filter :\n";;
List.filter neg lc;;
filter neg mlc;;

print_string "Test mem_assoc :\n";;
List.mem_assoc "ronan" lf;;
mem_assoc "ronan" mlf;;
List.mem_assoc "toto" lf;;
mem_assoc "toto" mlf;;

print_string "Test assoc :\n";;
List.assoc "hugo" lf;;
assoc "hugo" mlf;;
List.assoc "foobar" lf;;
assoc "foobar" mlf;;

print_string "Test split :\n";;
List.split lf;;
split mlf;;

print_string "Test remove_assoc :\n";;
List.remove_assoc "hugo" lf;;
remove_assoc "hugo" mlf;;
List.remove_assoc "toto" lf;;
remove_assoc "toto" mlf;;
