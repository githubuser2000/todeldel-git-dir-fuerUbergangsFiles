i# pipeline.py
from tcore import State, toggle
from ecol import toggle_loop
from rules import toggle_xor


def pipeline_python(nums, selected):
    # Phase 1: ECO-L (imperativ)
    s1 = toggle_loop(nums, set(selected))

    # Phase 2: T-CORE (Bedeutung)
    state = State(nums=nums, selected=set(selected))
    s2 = toggle(state).selected

    # Phase 3: algebraische Kurzform
    s3 = toggle_xor(set(selected), nums)

    assert s1 == s2 == s3
    return s3
