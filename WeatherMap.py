import requests

def get_weather(city):
    api_key = "YOUR_API_KEY"  # Replace with your OpenWeatherMap API key
    base_url = "https://api.openweathermap.org/data/2.5/weather"
    params = {
        "q": city,
        "appid": api_key,
        "units": "metric"  # You can change units to "imperial" for Fahrenheit
    }

    response = requests.get(base_url, params=params)
    data = response.json()

    if data["cod"] == 200:
        weather_info = {
            "City": data["name"],
            "Temperature (°C)": data["main"]["temp"],
            "Weather": data["weather"][0]["description"],
        }
        return weather_info
    else:
        return None

def main():
    print("Simple Weather App")
    city = input("Enter city name: ")
    weather_data = get_weather(city)

    if weather_data:
        print("\nWeather Information:")
        for key, value in weather_data.items():
            print(f"{key}: {value}")
    else:
        print("City not found or an error occurred. Please try again.")

if __name__ == "__main__":
    main()
