(* 2.1 Tipo de dado algébrico *)
type forma =
  | Circulo of float                 (* raio *)
  | Retangulo of float * float       (* largura, altura *)


(* ==================================================== *)
(* 2.2 Função area com pattern matching *)
let pi = 3.14

let area (f : forma) : float =
  match f with
  | Circulo r -> pi *. r *. r
  | Retangulo (l, a) -> l *. a


(* ==================================================== *)
(* Exemplos *)
let () =
  let f1 = Circulo 10.0 in
  let f2 = Retangulo (5.0, 3.0) in
  Printf.printf "Área do círculo: %.2f\n" (area f1);
  Printf.printf "Área do retângulo: %.2f\n" (area f2)
