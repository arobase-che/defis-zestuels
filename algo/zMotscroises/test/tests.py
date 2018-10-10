import pytest
import random

# you must create the search function before running tests
from crossword import search

random.seed(0)

# helper to build random patterns
def randword():
    sz = random.randint(3, 8)
    return ''.join(random.choice('aeiouy___')
                   for _ in range(sz))

tests = [
    ('z_s_e', ['zeste']),
    ('p__l__d', ['pillard']),
    ('q___n__', ['quignon']),
    ('y__a', ['yoga']),
    ('l__i__n', ['liaison']),
    ('t_x_n', ['taxon', 'texan']),
    ('_e_ayo__', ['relayons', 'repayons']),
    ('l__b', []),
]

@pytest.fixture
def wordlst():
    with open('../../mots-fr-accents.txt') as fp:
        return [line.strip() for line in fp]

@pytest.mark.parametrize('pattern, excepted', tests)
def test_search(pattern, excepted, wordlst):
    assert search(pattern, wordlst) == excepted

@pytest.mark.parametrize('rand_pattern', [
    randword() for _ in range(30)
])
def test_random(rand_pattern, wordlst):
    ret = search(rand_pattern, wordlst)
    assert all(all(p == '_' or p == c
               for p, c in zip(rand_pattern, w))
               for w in ret)
