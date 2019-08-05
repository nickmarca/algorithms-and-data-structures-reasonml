let isPalindrome = (s: string) => {
  s == StringReversal.reverseString(s);
};

let rec helper = (~it=0, s: string) =>
  if (it == String.length(s)) {
    true;
  } else {
    s.[it] == s.[String.length(s) - 1 - it] && helper(~it=it + 1, s);
  };

let isPalindrome2 = (s: string) => {
  helper(s);
};
