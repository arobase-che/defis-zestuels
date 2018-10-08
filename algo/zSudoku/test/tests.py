# coding: utf8

import pytest

# you must create the solve function before running tests
from solver import solve

# number of valid grids to test
NVALID = 100

# read sudoku grids
with open('../top1465.txt', 'r') as fp:
    grids = [line.strip() for line in fp if len(line) >= 81]

# read solution grids
with open('../top1465-solutions.txt', 'r') as fp:
    solutions = [line.strip() for line in fp if len(line) >= 81]

@pytest.mark.parametrize(
    'grid, solution', list(zip(grids, solutions))[:NVALID]
)

# valid grids test
def test_valid_grid(grid, solution):
    assert solve(grid) == solution

# invalid grid test
def test_invalid_grid():
    invalid = '123456789' * 9
    ret = solve(invalid)
    assert ret is None or ret == ''

#TODO: adding more failing cases
