import requests

def get_open_issues(repo_owner, repo_name):
    # GitHub API endpoint for open issues in a repository
    url = f'https://api.github.com/repos/{repo_owner}/{repo_name}/issues?state=open'

    try:
        # Send a GET request to the GitHub API
        response = requests.get(url)

        # Check if the request was successful (status code 200)
        if response.status_code == 200:
            # Parse the JSON response
            issues = response.json()

            # Display the open issues
            print(f"Open issues in {repo_owner}/{repo_name}:")
            for issue in issues:
                print(f"- {issue['title']} (#{issue['number']})")

        else:
            print(f"Failed to retrieve open issues (HTTP {response.status_code})")

    except Exception as e:
        print(f"An error occurred: {str(e)}")

if __name__ == "__main__":
    repo_owner = input("Enter the repository owner: ")
    repo_name = input("Enter the repository name: ")
    get_open_issues(repo_owner, repo_name)
