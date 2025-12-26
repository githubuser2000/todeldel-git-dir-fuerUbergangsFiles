import math

def n_to_grad(x):
    if math.isinf(x):
        return 0.0 if x > 0 else 180.0
    alpha = math.degrees(math.atan(1/x))
    # Ergebnis in 0..180 normalisieren
    return (alpha + 180) % 180
