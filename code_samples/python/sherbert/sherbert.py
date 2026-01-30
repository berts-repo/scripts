"""
sherbert.py
Run: python3 sherbert.py
"""
import json
import os

def get_recipe_files(directory):
    return [
        f
        for f in os.listdir(directory)
        if os.path.isfile(os.path.join(directory, f)) and f.lower().endswith(".json")
    ]

def load_recipe(file_path):
    with open(file_path, "r", encoding="utf-8") as file:
        return json.load(file)

def sum_ingredients(recipes):
    total_ingredients = {}
    for recipe in recipes:
        for ingredient, amount in recipe.items():
            if ingredient in total_ingredients:
                total_ingredients[ingredient] += amount
            else:
                total_ingredients[ingredient] = amount
    return total_ingredients

def print_ingredients(total_ingredients):
    print("\nTotal ingredients needed:")
    for ingredient, amount in total_ingredients.items():
        print(f"{ingredient}: {amount}")

def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    directory = os.path.join(script_dir, "recipes-form")
    recipes = []
    
    while True:
        recipe_files = get_recipe_files(directory)
        print("Available recipes:")
        for i, file in enumerate(recipe_files):
            print(f"{i + 1}. {file}")
        
        choice = input("Enter the number of the recipe to add (or 'done' to finish): ")
        if choice.lower() == 'done':
            break
        
        try:
            choice_index = int(choice) - 1
            if 0 <= choice_index < len(recipe_files):
                recipe_path = os.path.join(directory, recipe_files[choice_index])
                recipe = load_recipe(recipe_path)
                recipes.append(recipe)
            else:
                print("Invalid choice. Please try again.")
        except ValueError:
            print("Invalid input. Please enter a number.")
    
    total_ingredients = sum_ingredients(recipes)
    if not total_ingredients:
        print("\nNo recipes selected.")
        return
    
    while True:
        action = input("\nEnter 'print' to view the ingredients or 'exit' to quit: ")
        if action.lower() == 'print':
            print_ingredients(total_ingredients)
        elif action.lower() == 'exit':
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please enter 'print' or 'exit'.")

if __name__ == "__main__":
    main()
