# Stepper Motor Driver
This is Driver for 28BYJ-48 Model of Stepper Motor and Arch Layer Applied

## Architecture Layer Applied
- APP Folder has the Main Application --> main.c
- HAL Folder has Stepper Motor Driver (Just Include Interface.h in ur main program).
- MCAL Folder has DIO Driver (which is needed because HAL Layer Connecting to MCAL Layer).
- Services Folder has .h Files has useful Macros to make the code easier and more readable.

## Stepper Motor Features
- Control Stepper Motor With Choosen type (Half Step Mode or Full Step Mode)
- Go to target Degree
- Choosing target Speed (There's 3 Different Speeds).
- Choose Target Direction (CW or CCW).

- Stop The Motor


###### Configration File
* Go to Config File in HAL -> 06- Stepper -> Stepper.config.h
* Edit coils pins depend on wire Color.