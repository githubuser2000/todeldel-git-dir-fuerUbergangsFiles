# ecol.py
from typing import Iterable, Set


def contains(s: Set[int], v: int) -> bool:
    return v in s


def add(s: Set[int], v: int) -> None:
    s.add(v)


def remove(s: Set[int], v: int) -> None:
    s.remove(v)


def toggle_loop(nums: Iterable[int], selected: Set[int]) -> Set[int]:
    for v in nums:
        if contains(selected, v):
            remove(selected, v)
        else:
            add(selected, v)
    return selected
