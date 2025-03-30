import requests
from bs4 import BeautifulSoup

def fetch_table(url):
    
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find('table')
    
    return table

def build_grid(url):
    
    table = fetch_table(url)
    points = []
    rows = table.find_all('tr')[1:]
    
    for row in rows:
        
        columns = row.find_all('td')
        parts = [col.get_text(strip=True) for col in columns[:3]]
        
        x, char, y = parts[0], parts[1], parts[2]
        x, y = int(x), int(y)
        points.append((x, y, char))
    
    max_x = max(p[0] for p in points)
    max_y = max(p[1] for p in points)


    grid = [[" " for _ in range(max_y + 1)] for _ in range(max_x + 1)]

    for x, y, char in points:
        grid[x][max_y-y] = char
    
    for row in grid:
        print("".join(row))

def main():
    url = "https://docs.google.com/document/d/e/2PACX-1vSZ1vDD85PCR1d5QC2XwbXClC1Kuh3a4u0y3VbTvTFQI53erafhUkGot24ulET8ZRqFSzYoi3pLTGwM/pub"
    build_grid(url)


if __name__ == "__main__":
    main()

