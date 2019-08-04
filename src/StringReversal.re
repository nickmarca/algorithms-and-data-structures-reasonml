module Helpers = {
  let rec reverse_string = (~it=0, ~r="", s): string => {
    it < String.length(s)
      ? reverse_string(~it=it + 1, ~r=Char.escaped(s.[it]) ++ r, s) : r;
  };
};

let reverseString = (s: string) => {
  Helpers.reverse_string(s);
};
