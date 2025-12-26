# rules.py
from typing import Iterable, Set


def toggle_xor(selected: Set[int], nums: Iterable[int]) -> Set[int]:
    """
    S := S ⊕ nums
    """
    result = set(selected)
    for v in nums:
        if v in result:
            result.remove(v)
        else:
            result.add(v)
    return result
