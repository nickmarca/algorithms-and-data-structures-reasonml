const { chunk } = require('./Chunk.bs');

describe('Chunk', () => {
  test('CASE A', () => {
    expect(chunk([1,2,3], 2)).toEqual([[1, 2], [3]]);
  });

  test('CASE B', () => {
    const a = [0, 2, 5, 8, 11, 67, 22, 1];
    expect(chunk(a, a.length)).toEqual([[...a]]);
  });

  test('CASE C', () => {
    const a = [0];
    expect(chunk(a, 1)).toEqual([[0]]);
  });

  test('CASE D', () => {
    const a = [0, 2, 6, 7, 1, 5, 102, 6];
    expect(chunk(a, 4)).toEqual([[0, 2, 6, 7], [1, 5, 102, 6]]);
  });

  test('CASE E', () => {
    const a = [1, 2, 3, 4];
    expect(chunk(a, 1)).toEqual([[1], [2], [3], [4]]);
  });
});
