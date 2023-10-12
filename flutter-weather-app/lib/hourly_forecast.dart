import 'package:flutter/material.dart';

class HourlyForecast extends StatelessWidget {
  final IconData icon;
  final String time;
  final String temp;
  const HourlyForecast({
    super.key,
    required this.icon,
    required this.time,
    required this.temp,
    });

  @override
  Widget build(BuildContext context) {
    return Card(
      elevation: 10,
      child: Container(
        width: 100,
        padding: const EdgeInsets.all(8.0),
        decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(5),
        ),
        child:  Column(
          children: [
            Text(
              time,
              style: const TextStyle(
                fontSize: 20,
                fontWeight: FontWeight.bold,
              ),
            ),
                      
            const SizedBox(height: 10,),
                      
            Icon(icon, size: 32,),
                      
            const SizedBox(height: 10,),
            
            Text(
              temp,
              style: const TextStyle(
                fontSize: 15,
              ),
            )
          ],
        ),
      ),
    );
  }
}