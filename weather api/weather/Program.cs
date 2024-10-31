using System;
using System.Net.Http;
using System.Threading.Tasks;

class Program
{
    // Create a static instance of HttpClient
    static readonly HttpClient client = new HttpClient();

    static async Task Main()
    {
        try
        {
            // Your OpenWeather API key
            string apiKey = "5784eb9613b67cdaccf583eadc08e2d2"; // Replace with your actual API key
            double latitude = 40.7128; // Example: New York City latitude
            double longitude = -74.0060; // Example: New York City longitude
            string exclude = "minutely,hourly"; // Optional: parts to exclude

            // Construct the request URL
            string url = $"https://api.openweathermap.org/data/2.5/weather?lat=40.5622&lon=-111.9297&appid={apiKey}";

            // Make the GET request
            HttpResponseMessage response = await client.GetAsync(url);
            response.EnsureSuccessStatusCode(); // Throw if not a success code.

            // Read the response body as a string
            string responseBody = await response.Content.ReadAsStringAsync();

            // Print the response body (JSON data)
            Console.WriteLine(responseBody);
        }
        catch (HttpRequestException e)
        {
            // Handle any errors that occur during the request
            Console.WriteLine($"Error: {e.Message}");
        }
    }
}