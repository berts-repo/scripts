from git import Repo
import requests

# GitHub username or organization name
username = "B3rticus"

# Personal access token for GitHub authentication
access_token = "<redacted>"

def get_repo_list():
    headers = {
        "Authorization": f"token {access_token}",
        "Accept": "application/vnd.github.v3+json"
    }
    repos = []
    page = 1
    while True:
        api_url = f"https://api.github.com/user/repos?per_page=100&page={page}"
        try:
            # Fetch list of repositories from GitHub API
            response = requests.get(api_url, headers=headers)
            response.raise_for_status()  # Raise an exception for bad responses
            page_repos = response.json()
            if not page_repos:
                break
            repos.extend(page_repos)
            page += 1
        except requests.exceptions.RequestException as e:
            print(f"Error fetching repositories: {e}")
            break
    return repos

def clone_repositories():
    try:
        # Fetch list of repositories
        repos = get_repo_list()

        # Clone each repository
        for repo in repos:
            repo_name = repo['name']
            repo_clone_url = repo['clone_url']
            print(f"Cloning {repo_name}...")

            # Clone the repository using gitpython
            Repo.clone_from(repo_clone_url, f"./{repo_name}")

        print("All repositories cloned successfully!")

    except Exception as e:
        print(f"An error occurred: {str(e)}")

if __name__ == "__main__":
    clone_repositories()
