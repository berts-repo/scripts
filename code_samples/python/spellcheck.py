"""
spellcheck.py
Run: python3 spellcheck.py

Note: Requires the third-party package "pyspellchecker".
Install: python3 -m pip install pyspellchecker
"""

try:
    from spellchecker import SpellChecker
except ImportError:
    SpellChecker = None

def spell_check():
    if SpellChecker is None:
        print("Missing dependency: pyspellchecker")
        print("Install with: python3 -m pip install pyspellchecker")
        return

    spell = SpellChecker()

    # Get user input
    text = input("Enter text for spell checking: ")

    # Split text into words and check spelling
    misspelled = spell.unknown(text.split())

    if len(misspelled) == 0:
        print("No misspelled words found!")
    else:
        for word in misspelled:
            print(f"Did you mean '{spell.correction(word)}' for '{word}'?")

if __name__ == "__main__":
    spell_check()
