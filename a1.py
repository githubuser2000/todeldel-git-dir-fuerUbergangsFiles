# tcore.py
from dataclasses import dataclass
from typing import List, Set


@dataclass
class State:
    nums: List[int]
    selected: Set[int]


def toggle(state: State) -> State:
    """
    Toggle : State -> State
    Involution: toggle(toggle(S)) == S
    """
    selected = set(state.selected)

    for v in state.nums:
        if v in selected:
            selected.remove(v)
        else:
            selected.add(v)

    return State(nums=list(state.nums), selected=selected)
