//let run1 = (str: string) => {
//  let re = [%re "/[aeiou]/ig"];
//  let break = ref(false);
//  let count = ref(0);
//
//  while (! break^) {
//    let result = Js.Re.exec_(re, str);
//
//    switch (result) {
//    | Some(value) =>
//      let captures = Js.Re.captures(value);
//      Js.Nullable.iter(captures[0], (. v) => Js.log(v));
//      ();
//    | None => ()
//    };
//
//    switch (result) {
//    | Some(value) => count := count^ + 1
//    | None => break := true
//    };
//    ();
//  };
//
//  count^;
//};

let run = (str: string) => {
  let re = [%re "/[aeiou]/ig"];

  let rec go = (i: int) => {
    let result = Js.Re.exec_(re, str);

    switch (result) {
    | Some(value) => go(i + 1)
    | None => i
    };
  };

  go(0);
};