import csv
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

# Part 1: Scrape product listings
base_url = "https://www.amazon.in/s?k=bags&crid=2M096C61O4MLT&qid=1653308124&sprefix=ba%2Caps%2C283&ref=sr_pg_"
pages_to_scrape = 20

data = []

for page in range(1, pages_to_scrape + 1):
    url = base_url + str(page)
    response = requests.get(url)
    soup = BeautifulSoup(response.content, "html.parser")
    
    products = soup.find_all("div", class_="s-result-item")
    
    for product in products:
        product_link = product.find("a", class_="a-link-normal")
        if product_link:
            product_url = urljoin("https://www.amazon.in/", product_link.get("href"))
            
            product_name_element = product.find("span", class_="a-text-normal")
            product_name = product_name_element.get_text(strip=True) if product_name_element else "No product name available"
            
            product_price_element = product.find("span", class_="a-offscreen")
            product_price = product_price_element.get_text(strip=True) if product_price_element else "Price not available"
            
            rating_element = product.find("span", class_="a-icon-alt")
            rating = rating_element.get_text(strip=True) if rating_element else "Not available"
            
            review_count_element = product.find("span", {"class": "a-size-base", "dir": "auto"})
            review_count = review_count_element.get_text(strip=True) if review_count_element else "0"
            
            data.append({
                "Product URL": product_url,
                "Product Name": product_name,
                "Product Price": product_price,
                "Rating": rating,
                "Number of Reviews": review_count
            })
        else:
            print("Product link not found for a product. Skipping...")


# Part 2: Scraping additional product information
for item in data:
    response = requests.get(item["Product URL"])
    soup = BeautifulSoup(response.content, "html.parser")
    
    description_element = soup.find("meta", {"name": "description"})
    description = description_element.get("content") if description_element else ""
    
    asin_element = soup.find("th", string="ASIN")
    asin = asin_element.find_next("td").get_text(strip=True) if asin_element else ""
    
    product_description_element = soup.find("div", {"id": "productDescription"})
    product_description = product_description_element.get_text(strip=True) if product_description_element else ""
    
    manufacturer_element = soup.find("a", {"id": "bylineInfo"})
    manufacturer = manufacturer_element.get_text(strip=True) if manufacturer_element else ""
    
    item["Description"] = description
    item["ASIN"] = asin
    item["Product Description"] = product_description
    item["Manufacturer"] = manufacturer

# Export data to CSV
csv_file = "amazon_products.csv"
csv_columns = ["Product URL", "Product Name", "Product Price", "Rating", "Number of Reviews",
               "Description", "ASIN", "Product Description", "Manufacturer"]

with open(csv_file, "w", newline="", encoding="utf-8") as csvfile:
    writer = csv.DictWriter(csvfile, fieldnames=csv_columns)
    writer.writeheader()
    for item in data:
        writer.writerow(item)

print("Scraping and CSV export complete.")
