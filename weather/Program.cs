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
            var response = await fetchApi();
            if (response != null)
            {
                string responseBody = await response.Content.ReadAsStringAsync();
                Console.WriteLine(responseBody);
            }
        }
        catch (Exception e)
        {
            Console.WriteLine($"An error occurred: {e.Message}");
        }
    }

    public static async Task<HttpResponseMessage> fetchApi()
    {
        try
        {
            // Your OpenWeather API key
            string apiKey = "5784eb9613b67cdaccf583eadc08e2d2"; // Replace with your actual API key

            // Construct the request URL
            string url = $"https://api.openweathermap.org/data/2.5/weather?lat=40.5622&lon=-111.9297&appid={apiKey}";

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
}