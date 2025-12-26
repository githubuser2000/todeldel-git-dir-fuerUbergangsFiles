# main.py
from pipeline import pipeline_python

def main():
    nums = [1, 2, 3, 4, 5]
    selected = set()

    result = pipeline_python(nums, selected)
    print("Result:", result)


if __name__ == "__main__":
    main()
