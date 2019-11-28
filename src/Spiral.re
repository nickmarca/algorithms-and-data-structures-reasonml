type cursor = (int, int);

type canWalkResponse =
  | Yes
  | No;

type direction =
  | Left
  | Down
  | Right
  | Up;

type walk = (int, cursor, direction);

type walkResponse =
  | Walked(walk)
  | Completed
  | Refused;

let buildWalkingLeft = (~matrix, ~lastWalk) => {
  let (value, (x, y), _) = lastWalk;
  let nextY = y + 1;
  () => {
    let newVal = value + 1;
    matrix[x][nextY] = Some(newVal);
    (newVal, (x, nextY), Left);
  };
};

let buildWalkingRight = (~matrix, ~lastWalk) => {
  let (value, (x, y), _) = lastWalk;
  let nextY = y - 1;
  () => {
    let newVal = value + 1;
    matrix[x][nextY] = Some(newVal);
    (newVal, (x, nextY), Right);
  };
};

let buildWalkingUp = (~matrix, ~lastWalk) => {
  let (value, (x, y), _) = lastWalk;
  let nextX = x - 1;
  () => {
    let newVal = value + 1;
    matrix[nextX][y] = Some(newVal);
    (newVal, (nextX, y), Up);
  };
};

let buildWalkingDown = (~matrix, ~lastWalk) => {
  let (value, (x, y), _) = lastWalk;
  let nextX = x + 1;
  () => {
    let newVal = value + 1;
    matrix[nextX][y] = Some(newVal);
    (newVal, (nextX, y), Down);
  };
};

let buildWalking = (~matrix, ~lastWalk, ~towards: direction) => {
  switch (towards) {
  | Left => buildWalkingLeft(~matrix, ~lastWalk)
  | Right => buildWalkingRight(~matrix, ~lastWalk)
  | Up => buildWalkingUp(~matrix, ~lastWalk)
  | Down => buildWalkingDown(~matrix, ~lastWalk)
  };
};

let optionToBool = opt =>
  switch (opt) {
  | None => false
  | Some(_) => true
  };

let canWalkLeft = (~matrix, ~lastWalk: walk): canWalkResponse => {
  let (_, (x, y), _) = lastWalk;
  let nextY = y + 1;
  let conditions =
    nextY < Array.length(matrix) && !optionToBool(matrix[x][nextY]);

  conditions ? Yes : No;
};

let canWalkDown = (~matrix, ~lastWalk: walk): canWalkResponse => {
  let (_, (x, y), _) = lastWalk;
  let nextX = x + 1;
  let conditions =
    nextX < Array.length(matrix) && !optionToBool(matrix[nextX][y]);

  conditions ? Yes : No;
};

let canWalkRight = (~matrix, ~lastWalk: walk): canWalkResponse => {
  let (_, (x, y), _) = lastWalk;
  let nextY = y - 1;
  let conditions = nextY >= 0 && !optionToBool(matrix[x][nextY]);

  conditions ? Yes : No;
};

let canWalkUp = (~matrix, ~lastWalk: walk): canWalkResponse => {
  let (_, (x, y), _) = lastWalk;
  let nextX = x - 1;
  let conditions = nextX >= 0 && !optionToBool(matrix[nextX][y]);

  conditions ? Yes : No;
};

let canWalk = (~matrix, ~lastWalk: walk, ~towards: direction): canWalkResponse => {
  switch (towards) {
  | Left => canWalkLeft(~matrix, ~lastWalk)
  | Right => canWalkRight(~matrix, ~lastWalk)
  | Up => canWalkUp(~matrix, ~lastWalk)
  | Down => canWalkDown(~matrix, ~lastWalk)
  };
};

let walkOrRefuse =
    (
      ~matrix: array(array(option(int))),
      ~lastWalk: walk,
      ~towards: direction,
    )
    : option(walk) => {
  let response = canWalk(~matrix, ~lastWalk, ~towards);

  switch (response) {
  | Yes => Some((buildWalking(~matrix, ~lastWalk, ~towards))())
  | No => None
  };
};

let changeDirection = (from): direction => {
  switch (from) {
  | Left => Down
  | Down => Right
  | Right => Up
  | Up => Left
  };
};

let optionToWalkResponse = (opt, matrixLength, counter): walkResponse => {
  switch (opt) {
  | Some(walk) => Walked(walk)
  | None => counter < matrixLength * matrixLength ? Refused : Completed
  };
};

let rec go = (~matrix, ~lastWalk: walk, ~towards: direction, ~counter: int) => {
  let response = walkOrRefuse(~matrix, ~lastWalk, ~towards);

  switch (optionToWalkResponse(response, Array.length(matrix), counter)) {
  | Walked(latestWalk) =>
    go(~matrix, ~lastWalk=latestWalk, ~towards, ~counter=counter + 1)
  | Refused =>
    go(~matrix, ~lastWalk, ~towards=changeDirection(towards), ~counter)
  | Completed => ()
  };
};

let run = (n: int) => {
  let matrix = Array.init(n, _ => Array.make(n, None));
  matrix[0][0] = Some(1);

  go(~matrix, ~lastWalk=(1, (0, 0), Left), ~towards=Left, ~counter=1);
  Js.log(matrix);

  matrix;
};