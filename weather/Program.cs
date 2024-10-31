
using System;
using System.Net.Http;
using System.Threading.Tasks;

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
}