import math

def grad_to_n(alpha_deg):
    rad = math.radians(alpha_deg)
    s = math.sin(rad)
    if abs(s) < 1e-12:
        return math.copysign(math.inf, math.cos(rad))  # n oder -n
    return math.cos(rad) / s   # cot(alpha)
