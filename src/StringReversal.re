let rec helper = (~it=0, ~r="", s): string => {
  it < String.length(s)
    ? helper(~it=it + 1, ~r=Char.escaped(s.[it]) ++ r, s) : r;
};

let reverseString = (s: string) => {
  helper(s);
};
