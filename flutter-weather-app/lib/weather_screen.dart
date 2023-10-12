import 'dart:convert';
import 'dart:ui';
import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:weather_app/env.dart';
import 'package:weather_app/extra_info.dart';
import 'package:weather_app/hourly_forecast.dart';
import 'package:http/http.dart' as http;

class WeatherScreen extends StatefulWidget {
  const WeatherScreen({super.key});

  @override
  State<WeatherScreen> createState() => _WeatherScreenState();
}

class _WeatherScreenState extends State<WeatherScreen> {

  final int forecastTabs = 6;
  String cityName = 'Sydney',countryname='australia';

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    getCurrentWeather();
  }
  
  Future<Map<String,dynamic>> getCurrentWeather() async{
    try{
      final res = await http.get(
        Uri.parse(
          'https://api.openweathermap.org/data/2.5/forecast?q=$cityName,$countryname&APPID=$apiKey'
        ),
      );

      final data = jsonDecode(res.body);

      if(data['cod']!='200'){
        throw 'Unexpected error';
      }

      //temp = data['list'][0]['main']['temp'];
      return data;
    }catch(e){
      throw e.toString();
    }
  }

  // List<Widget> createForecast(dynamic forecastData){
  //   List<Widget> forecasts = [];

  //   for(int i=1 ; i<= forecastTabs ; i++){
  //   final foreTemp = forecastData[i+1]['main']['temp'];
  //   final foreSky = forecastData[i+1]['weather'][0]['main'];
  //   final foreTime = forecastData[i+1]['dt_txt'].split(' ')[1];
  //     forecasts.add(
  //       HourlyForecast(
  //         icon: foreSky == 'Clouds' || foreSky == 'Rain' ? Icons.cloud : Icons.sunny ,
  //         time: "$foreTime", 
  //         temp: "$foreTemp K")
  //     );
  //   }
  //   return forecasts;
  // }


  @override
  Widget build(BuildContext context) {
    return  Scaffold(
      appBar: AppBar(
        title: const Text(
          "Weather App", 
          style: TextStyle(
            fontWeight: FontWeight.bold,
            ),
          ),
        centerTitle: true,
        actions:  [
          IconButton(onPressed: (){
            setState(() {});
          }, icon: const Icon(Icons.refresh))
        ],
      ),

      body: FutureBuilder(
        future: getCurrentWeather(),
        builder: (context, snapshot) {

          if(snapshot.connectionState == ConnectionState.waiting){
            return const Center(child: CircularProgressIndicator.adaptive());
          }

          if(snapshot.hasError){
            return Text(snapshot.error.toString());
          }

          final data = snapshot.data!;
          final currentWeatherData = data['list'][0];
          final currentTemp = currentWeatherData['main']['temp'];
          final currentSky = currentWeatherData['weather'][0]['main'];
          final currentHumidity = currentWeatherData['main']['humidity'];
          final currentPress = currentWeatherData['main']['pressure'];
          final currentWind = currentWeatherData['wind']['speed'];
          final forecastData = data['list'];
          return Padding(
          padding:  const EdgeInsets.all(8.0),
          child:  Column(
            
            children: [
               SizedBox(
                width: double.infinity,
                child: Card(
                  elevation: 10,
                  shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10)),
                  child: ClipRect(
                    child: BackdropFilter(
                      filter: ImageFilter.blur(
                        sigmaX: 10,
                        sigmaY: 10,
                      ),
                      child: Padding(
                        padding:  const EdgeInsets.all(20.0),
                        child:  Column(
                          children: [
                            Text( 
                              "$currentTemp K",
                              style: const TextStyle(fontSize: 35),
                            ),
                            const SizedBox(height: 15,),
                            Icon(
                              currentSky=='Clouds' || currentSky=='Rain' ? Icons.cloud : Icons.sunny, 
                              size: 70,),
                            const SizedBox(height: 30,),
                            Text(  
                              "$currentSky",
                              style: const TextStyle(
                                fontSize: 20,
                              ),
                            ),
                          ],
                        ),
                      ),
                    ),
                  ),
                ),
              ),
              const SizedBox(height: 10,),
              const Align(
                alignment: Alignment.centerLeft,
                child: Text(
                  "Hourly Forecast",
                  style: TextStyle(
                    fontSize: 25,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
              
              const SizedBox(height: 10,),
        
              SingleChildScrollView(
                scrollDirection: Axis.horizontal,
                child: Row(
                  children: [
                    SizedBox(
                      height: 130,
                      width: 500,
                      child: ListView.builder(
                        scrollDirection: Axis.horizontal,
                        itemCount: forecastTabs,
                        itemBuilder: (context , index){
                        final foreTemp = forecastData[index+1]['main']['temp'];
                        final foreSky = forecastData[index+1]['weather'][0]['main'];
                        //final foreTime = forecastData[index+1]['dt_txt'].split(' ')[1]; //doing without the intl pkg
                        final time = DateTime.parse(forecastData[index+1]['dt_txt']);
                        return HourlyForecast(
                          icon: foreSky == 'Clouds' || foreSky == 'Rain' ? Icons.cloud : Icons.sunny ,
                          time: DateFormat.j().format(time),
                          temp: '$foreTemp',
                          );
                        },
                        
                      ),
                    )
                  ],
                ),
              ),
              
              const SizedBox(height: 20,),
              
              const Align(
                alignment: Alignment.centerLeft,
                child: Text(
                  "Additional Information",
                  style: TextStyle(
                    fontSize: 25,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
              
              const SizedBox(height: 4,),
              
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceAround,
                children: [
                  ExtraInfo(
                    icon: Icons.water_drop,
                    label: "Humidity",
                    value: "$currentHumidity %",
                  ),
                  ExtraInfo(
                    icon: Icons.air,
                    label: "Wind",
                    value: "$currentWind m/s",
                  ),
                  ExtraInfo(
                    icon: Icons.beach_access,
                    label: "Pressure",
                    value: "$currentPress hPa",
                  ),
                ],
              )
            ],
          ),
        );
        },
      ),
    );
  }
}




