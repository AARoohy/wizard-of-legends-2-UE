# Wizard of Legends 2: Top-Down Unreal Game

Welcome to the Wizard of Legends 2 repository! This project is an assignment for Deadmage Studio. It is a top-down game developed using Unreal Engine, inspired by the original Wizard of Legends.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contact](#contact)

## Introduction

Wizard of Legends 2 is a fast-paced, action-packed top-down game where players take on the role of a powerful wizard. The game focuses on quick reflexes, strategic spellcasting, and overcoming various enemies and challenges. This project is an assignment for Deadmage Studio and is designed to showcase my skills in Unreal Engine and game development.

## Features

- **Stat System:** The stat system in Wizard of Legends 2 is a cornerstone of the game's mechanics, designed to be fully flexible and dynamic. Implemented entirely in C++ code, this event-based system allows for seamless integration and real-time adjustments. The stat system incorporates several design patterns to ensure flexibility and scalability:
   - **Factory Method Pattern**
   - **Observer Pattern**
   - **Composite Pattern**
   - **Strategy Pattern**
   - **Decorator Pattern (Implicit)**
  
- **Ability System:** The ability system in Wizard of Legends 2 is designed to be flexible and efficient, allowing for the rapid creation of new abilities and real-time adjustments. The ability system incorporates several design patterns to ensure flexibility and scalability:
   - **Factory Method Pattern**
   - **Observer Pattern**
   - **State Pattern**
  
- **Controller/Keyboard Support:** Wizard of Legends 2 provides full support for both controllers and keyboards, ensuring a versatile and accessible gameplay experience.
- **Audio Effects:** Engaging sound effects and background music.
- **Smooth Controls:** Intuitive and responsive player controls.
  

### Key Features of the Stat System:

- **Flexibility:** The stat system is highly modular, enabling easy addition or modification of stats without affecting the overall system.
- **Event-Based:** This design ensures that changes in stats are immediately reflected throughout the game, allowing for dynamic interactions and real-time updates.
- **Scalability:** The system can handle a wide range of stats, from basic health and mana to more complex attributes like attack speed and critical hit chance.
- **Efficiency:** Written in C++, the system is optimized for performance, ensuring smooth gameplay even with numerous active stat modifications.
- **Integration:** Easily integrates with other game systems such as inventory, abilities, and character progression, providing a cohesive experience.


### Key Features of the Ability System:

- **Ease of Creation:** The system allows for quick and easy creation of new abilities, reducing development time and enabling rapid iteration.
- **Ability Database:** Offers an ability database that can change the abilities of players in real-time, providing a dynamic and adaptable gameplay experience.
- **Integration:** Seamlessly integrates with the stat system and other game mechanics, ensuring a cohesive and balanced game environment.
- **Flexibility:** Highly modular design allows for easy customization and expansion of abilities to meet diverse gameplay needs.


### Key Features of Controller/Keyboard Support:

- **Accessibility:** Designed to be accessible for players with various control preferences, enhancing the overall user experience.
- **Enhanced Input System:** Utilizes Unreal Engine's new Enhanced Input system for more responsive and precise control mapping.

This stat system, ability system, and controller/keyboard support showcase my proficiency in designing flexible, scalable, and efficient game mechanics that enhance the player experience.

## Installation

To get a local copy up and running, follow these simple steps:

1. **Clone the repository:**
   ```sh
   git clone https://github.com/AARoohy/wizard-of-legends-2-UE.git
   ```
2. **Navigate to the project directory:**
   ```sh
   cd wizard-of-legends-2
   ```
3. **Open the project in Unreal Engine**
   - Launch Unreal Engine.
   - Open the project file located in the repository.

## Usage
Once the project is set up, you can run the game directly from Unreal Engine by clicking the "Play" button. You can also package the project to create a standalone executable for easier distribution and testing.

| Actions                    | PC                                                                                                                                | Controller                                                                                                                               |
|----------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------|
| Move                       | <img src="https://raw.githubusercontent.com/AARoohy/wizard-of-legends-2-UE/main/AbilityActionImage/Move_PC.png" width="50">       | <img src="https://raw.githubusercontent.com/AARoohy/wizard-of-legends-2-UE/main/AbilityActionImage/Move_Controller.png" width="50">      |
| Skill 1                    | <img src="https://raw.githubusercontent.com/AARoohy/wizard-of-legends-2-UE/main/AbilityActionImage/BaseSkill_PC.png" width="50">  | <img src="https://raw.githubusercontent.com/AARoohy/wizard-of-legends-2-UE/main/AbilityActionImage/BaseSkill_Controller.png" width="50"> |
| Dash                       | <img src="https://raw.githubusercontent.com/AARoohy/wizard-of-legends-2-UE/main/AbilityActionImage/Dash_PC.png" width="50">       | <img src="https://raw.githubusercontent.com/AARoohy/wizard-of-legends-2-UE/main/AbilityActionImage/Dash_Controller.png" width="50">      |
| Self Damage (Test Purpose) | <img src="https://raw.githubusercontent.com/AARoohy/wizard-of-legends-2-UE/main/AbilityActionImage/SlefDamage_PC.png" width="50"> |                                                                                                                                          |
## Contact
[AmirAbbasRoohy@gmail.com](mailto:amirabbasroohy@gmail.com)


