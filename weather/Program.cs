using System;
using System.Net.Http;
using System.Threading.Tasks;
using System.Text.Json;

class Program
{
    // Create a static instance of HttpClient
    static readonly HttpClient client = new HttpClient();

    static async Task Main()
    {
        float[] coordinates = Questions();
        try
        {
            var response = await fetchApi(coordinates);
            if (response != null)
            {
                string responseBody = await response.Content.ReadAsStringAsync();
                Console.WriteLine(responseBody);
                FilterData(responseBody);
            }
        }
        catch (Exception e)
        {
            Console.WriteLine($"An error occurred: {e.Message}");
        }
    }

    public static async Task<HttpResponseMessage> fetchApi(float[] coordinates)
    {
        try
        {
            // Your OpenWeather API key
            string apiKey = "5784eb9613b67cdaccf583eadc08e2d2"; // Replace with your actual API key

            // Construct the request URL
            string url = $"https://api.openweathermap.org/data/2.5/weather?lat={coordinates[0]}&lon={coordinates[1]}&appid={apiKey}";

            // Make the GET request
            HttpResponseMessage response = await client.GetAsync(url);
            response.EnsureSuccessStatusCode(); // Throw if not a success code.

            return response;
        }
        catch (HttpRequestException e)
        {
            // Handle any errors that occur during the request
            Console.WriteLine($"Error: {e.Message}");
            return null;
        }
    }

    public static float[] Questions()
    {
        Console.WriteLine("What is the latitude of the place?");
        float latitude = float.Parse(Console.ReadLine());

        Console.WriteLine("What is the longitude of the place?");
        float longitude = float.Parse(Console.ReadLine());

        float[] coordinates = { latitude, longitude };
        return coordinates;
    }

    public static void FilterData(string jsonResponse)
    {
        var weatherData = JsonSerializer.Deserialize<WeatherData>(jsonResponse);

        Console.WriteLine("\nOptions:");
        Console.WriteLine("1. Location Name");
        Console.WriteLine("2. Temperature");
        Console.WriteLine("3. Weather Description");
        Console.WriteLine("4. Wind Speed");
        Console.WriteLine("5. Humidity");
        Console.WriteLine("6. Exit");

        bool done = false;
        while (!done)
        {
            Console.Write("\nEnter your choice (1-6): ");
            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    Console.WriteLine($"Location: {weatherData.name}");
                    break;
                case "2":
                    double tempFahrenheit = (weatherData.main.temp - 273.15) * 9/5 + 32;
                    Console.WriteLine($"Temperature: {tempFahrenheit:F1}°F");
                    break;
                case "3":
                    Console.WriteLine($"Weather: {weatherData.weather[0].description}");
                    break;
                case "4":
                    Console.WriteLine($"Wind Speed: {weatherData.wind.speed} m/s");
                    break;
                case "5":
                    Console.WriteLine($"Humidity: {weatherData.main.humidity}%");
                    break;
                case "6":
                    done = true;
                    Console.WriteLine("Exiting...");
                    break;
                default:
                    Console.WriteLine("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}

// Classes to match the JSON structure
public class WeatherData
{
    public Coord coord { get; set; }
    public Weather[] weather { get; set; }
    public string @base { get; set; }
    public Main main { get; set; }
    public int visibility { get; set; }
    public Wind wind { get; set; }
    public Clouds clouds { get; set; }
    public long dt { get; set; }
    public Sys sys { get; set; }
    public int timezone { get; set; }
    public int id { get; set; }
    public string name { get; set; }
    public int cod { get; set; }
}

public class Coord
{
    public float lon { get; set; }
    public float lat { get; set; }
}

public class Weather
{
    public int id { get; set; }
    public string main { get; set; }
    public string description { get; set; }
    public string icon { get; set; }
}

public class Main
{
    public float temp { get; set; }
    public float feels_like { get; set; }
    public float temp_min { get; set; }
    public float temp_max { get; set; }
    public int pressure { get; set; }
    public int humidity { get; set; }
    public int sea_level { get; set; }
    public int grnd_level { get; set; }
}

public class Wind
{
    public float speed { get; set; }
    public int deg { get; set; }
}

public class Clouds
{
    public int all { get; set; }
}

public class Sys
{
    public int type { get; set; }
    public int id { get; set; }
    public long sunrise { get; set; }
    public long sunset { get; set; }
}