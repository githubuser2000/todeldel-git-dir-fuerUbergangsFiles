#!/usr/bin/env python3
import sys

# ---------- Bitmask ----------
def to_bitmask(selected):
    mask = 0
    for n in selected:
        mask |= 1 << (n - 3)
    return mask

def from_bitmask(mask):
    return {i + 3 for i in range(7) if mask & (1 << i)}

ALLOWED = set(range(3, 10))

# ---------- Mode 1: Text Input ----------
def mode_text():
    line = input("Eingabe (z.B. 3 5 7): ")
    selected = set()

    for part in line.split():
        try:
            n = int(part)
            if n in ALLOWED:
                selected.add(n)
        except ValueError:
            pass

    print("Auswahl:", sorted(selected))
    print("Bitmaske:", to_bitmask(selected))

# ---------- Mode 2: Simple Toggle ----------
def mode_toggle():
    selected = set()

    while True:
        print("\033c", end="")  # clear screen
        for i in range(3, 10):
            mark = "x" if i in selected else " "
            print(f"[{mark}] {i}")

        c = input("\n3-9 toggle | q = fertig: ").strip()
        if c == "q":
            break
        if c.isdigit():
            v = int(c)
            if v in ALLOWED:
                if v in selected:
                    selected.remove(v)
                else:
                    selected.add(v)

    print("Auswahl:", sorted(selected))
    print("Bitmaske:", to_bitmask(selected))

# ---------- Mode 3: curses TUI ----------
def mode_curses():
    import curses

    def ui(stdscr):
        curses.curs_set(0)
        stdscr.keypad(True)

        selected = set()
        cursor = 0

        while True:
            stdscr.clear()
            for i in range(7):
                v = i + 3
                mark = "x" if v in selected else " "
                if i == cursor:
                    stdscr.attron(curses.A_REVERSE)
                stdscr.addstr(i, 0, f"[{mark}] {v}")
                if i == cursor:
                    stdscr.attroff(curses.A_REVERSE)

            key = stdscr.getch()
            if key == curses.KEY_UP and cursor > 0:
                cursor -= 1
            elif key == curses.KEY_DOWN and cursor < 6:
                cursor += 1
            elif key == ord(" "):
                v = cursor + 3
                if v in selected:
                    selected.remove(v)
                else:
                    selected.add(v)
            elif key in (10, 13):   # Enter
                return selected
            elif key == 27:        # ESC
                return set()

    selected = curses.wrapper(ui)
    print("Auswahl:", sorted(selected))
    print("Bitmaske:", to_bitmask(selected))

# ---------- Main ----------
def main():
    print(
        "Modus wählen:\n"
        "1 = Text-Eingabe\n"
        "2 = Toggle-TUI\n"
        "3 = curses-TUI\n"
    )

    try:
        mode = int(input("Auswahl: "))
    except ValueError:
        print("Ungueltig")
        return

    if mode == 1:
        mode_text()
    elif mode == 2:
        mode_toggle()
    elif mode == 3:
        mode_curses()
    else:
        print("Ungueltig")

if __name__ == "__main__":
    main()
