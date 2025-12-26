# emit_py.py
from typing import Set


def emit_toggle_py(S: Set[int], v: int) -> None:
    if v in S:
        S.remove(v)
    else:
        S.add(v)
