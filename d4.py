# quantifier.py
from typing import Iterable, Callable


def forall(xs: Iterable, fn: Callable):
    for x in xs:
        fn(x)
