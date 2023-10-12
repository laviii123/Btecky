import 'package:flutter/material.dart';

class ExtraInfo extends StatelessWidget {
  final IconData icon;
  final String label;
  final String value;
  const ExtraInfo({
    super.key,
    required this.icon,
    required this.label,
    required this.value,
  });

  @override
  Widget build(BuildContext context) {
    return Container(
      width: 100,
      padding: const EdgeInsetsDirectional.all(10),
      alignment: Alignment.center,
      child: Column(
        children: [
          Icon(icon,size: 40,),
          const SizedBox(height: 5,),
          Text(
            label,
            style: const TextStyle(
              fontSize: 18,
            ),
          ),
          const SizedBox(height: 5,),
          Text(
            value,
            style: const TextStyle(
              fontSize: 18,
              fontWeight: FontWeight.bold
            ),
          )
        ],
      ),
    );
  }
}
