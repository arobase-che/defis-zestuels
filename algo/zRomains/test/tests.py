import pytest

# you must create these functions before running tests
from romains import romain2int, int2romain


@pytest.mark.parametrize('romain, excepted', [
    # valid cases
    ('I', 1),
    ('V', 5),
    ('X', 10),
    ('L', 50),
    ('C', 100),
    ('D', 500),
    ('M', 1000),
    # composites
    ('II', 2),
    ('XX', 20),
    ('CC', 200),
    ('MM', 2000),
    # invalid cases
    ('S', None),
    ('R', None),
])
def test_rule1(romain, excepted):
    assert romain2int(romain) == excepted


@pytest.mark.parametrize('nb, excepted', [
    (1000, 'M'),
    (500, 'D'),
    (100, 'C'),
    (50, 'L'),
    (10, 'X'),
    (5, 'V'),
    (1, 'I'),
])
def test_rule1_inv(nb, excepted):
    assert int2romain(nb) == excepted


@pytest.mark.parametrize('romain, excepted', [
    # valid cases
    ('IV', 4),
    ('IX', 9),
    ('XL', 40),
    ('XC', 90),
    ('CD', 400),
    ('CM', 900),
    # invalid cases
    ('IIV', None),
    ('IIX', None),
    ('XXL', None),
    ('XXC', None),
    ('CCD', None),
    ('CCM', None),
    # composites
])
def test_rule2(romain, excepted):
    assert romain2int(romain) == excepted


@pytest.mark.parametrize('nb, excepted', [
    (900, 'CM'),
    (400, 'CD'),
    (90, 'XC'),
    (40, 'XL'),
    (9, 'IX'),
    (4, 'IV'),
])
def test_rule2_inv(nb, excepted):
    assert int2romain(nb) == excepted


@pytest.mark.parametrize('romain, excepted', [
    ('IL', None),
    ('IC', None),
    ('ID', None),
    ('IM', None),
    ('XD', None),
    ('XM', None),
])
def test_rule3(romain, excepted):
    assert romain2int(romain) == excepted


@pytest.mark.parametrize('nb, excepted', [
    (-1, None),
    (0, None),
    (5000, None),
])
def test_rule4(nb, excepted):
    assert int2romain(nb) == excepted


@pytest.mark.parametrize('romain, excepted', [
    ('VV', None),
    ('LL', None),
    ('DD', None),
])
def test_rule5(romain, excepted):
    assert romain2int(romain) == excepted


@pytest.mark.parametrize('nb', range(1, 501))
def test_more_cases(nb):
    assert romain2int(int2romain(nb)) == nb
