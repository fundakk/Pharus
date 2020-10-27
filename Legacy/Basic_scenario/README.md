# Basic scenarios

Basic scenarios are first step of delivering concent to recipent.

## Scenarios

Three subscenarios can be included in it's usage:

### 1. Substantive comment

This scenario allows to add extended explanation, comment, history fact, author biography to presented art piece, when no other forms are available. It would apply mostly to historical points, big scale installations, urban art, murals, or mappings, where scale or location do not allow to add printed description, or it would be easly missed.

Examples of usage:

- big scale mural, placed in urban enviroment, have no way of including informations about artist and/or comment about painting itself. Even if there is possible way to place it, with such scale it will be missed by visitors, that will take some space between facade and viewing area. Connecting to device will allow them to get these extra information on thier phones.
- placing informational boards on historical building or monuments is not possible. Device placed in it's close perimeter whill allow to share facts, photos ot other extra information about it's origin.
- large scale installation or videomapping during festival will be hard to to comment, or at least present the author, because any informational slate will be lost in it's scale. Using device will allow to deliver all information that could be shared, like artist bio, commentatory, photos or movies of construction etc.

### 2. Scattered content

Scattering content allows to take art outside of exhibitions area. Multiple devices located in different places (within city, country or even globally), allows to scatter visitors and apply more social distancing in terms of art delivery. Each device will deliver single artwork in digital form. Scattering also allows to move some forms art to places with more ambience.

Example of usage:

- painter or graphic that creates landscape or urban architecutural drawings/paintings can deliver his/her artworks exacly in places where they ware created.
- sound artist or musician can move his/her creations to places with better atmosphere or vibe, that can improve reception.
- any artist can place devices in public spaces or bars, as form of expresion or self-promotion.

### 3. Extended content

Extended content is similar to substantive comment, but instead of delivering comment or other text it will deliver other art in digital form. It would fit in galleries, or at art exhibitions, where limited space (or budget) do not allows to put extra artworks.

- gallery with limited space can only display few painting out of series. Device can be used to present other painting if digital form.
- emerging artist, instead of only his/her illustrations would like to show also his/her digital movies. Setting up for example 4 TV or projectors require equipment that he has no access to, and is above his budget in case of renting or buying. Setting up devices allows him to present his other budgetwise.

## Instructions

These isntructions presents way of editing or creating HTML files that will work directly with device, without a need to change C++ code on ESP, and are based on examples provided.

### File structure

All files must be placed in data folder of project. They cannot be placed in any other folder and need to have specific names:

| File name | Description | Mandatory |
| --- | --- | --- |
| index.html | Main html file, webpage | Yes |
| style.css | CSS file with styles | No |
| background.jpg | Background image for better visual reception | No |
| image1.jpg | First of four available image files supported by ESP code | No |
| image2.jpg | Second of four available image files supported by ESP code | No |
| image3.jpg | Third of four available image files supported by ESP code | No |
| image4.jpg | Fourth of four available image files supported by ESP code | No |
| movie.mp4 | Movie file available to be included on webpage | No |
| sound.mp3 | Sound file available to be included on webpage | No |

Be aware, that image files must be saved as jpg, not jpeg.

There is no limit on size of files, but be aware that this is not a high speed connection. 100 mb video file will load in very long time, but will not play continously, since transfer speed is to low. Stick with small files. After uploading files test with your phone if it works smoothly.

### Text

Create any, simple HTML file. To format it, you can use for example https://html-online.com/editor/. Save it as index.html and place it directly on SD card.

or

Open index.html file in examples/text folder with notepad. Edit out *EDIT THIS TITLE*, *EDIT THIS HEADER* and *Lorem ipsum* to your desired text. Save it as index.html. You can add background file as background.jpg. If you do not add background file, background will be black and text will be white.

Place both index.html and background.jpg (optionally - you can skip this file) directly on SD card.

### Image

Use index.html file in examples/image. Copy it to SD card and add your desired image file, saved in jpg format and name it image1.jpg. Image will be displayed to fill the screen area. Remaining space will black.

You can use Windows Paint or any other graphic editor to save file as jpg.

### Image gallery

Use index.html file in examples/image_gallery. Copy it to SD card and add your desired image files (maximum of four), saved in jpg format and named as image1.jpg, image2.jpg etc. Images will be displayed as 2x2 grid miniatures with black background. Clicking miniatures will display full sized version.

You can use Windows Paint or any other graphic editor to save file as jpg.

### Movie

Use index.html file in examples/movie. Copy it to SD card and add your desired movie file in mp4 format and name it movie.mp4. File will be loaded as playable movie.

If your movie is not in mp4 file format, you can use any online video converter, for example https://www.freeconvert.com/. In video converters click on to mp4 and upload your video.

### Sound

Use index.html file in examples/sound. Copy it to SD card and add your desired sound file in mp3 format and name it sound.mp3.
You can also add an image (saved as image1.jpg) as cover photo.
File will be loaded as playable sound.

If your sound is not in mp3 format, you need to to convert it. Again you can use https://www.freeconvert.com/.

### Advanced

This example breaks hardware.



You can create any html webpage to archive desired look.

But there are some limitation. Each webpage must be:
- single leveled (no hyperlinks to other pages)
- maximum of 5 images can be used (one of them is background image)
- one CSS file can be used
- one video can be embeded
- one sound file can be embeded
- single page cannot have more external files than 4 (total of 5 files). No matter size.


Will change:
Example of advanced usage includes webpage with:
- 6 sections, each with header
- background image
- 4 of these sections contain text and one photo
- each photo can be clicked and enlarged
- one section contains video file
- one section contains sound file
- CSS file with styles for header and text

This setup covers basic scenarios and can be implemented without changes in project code.
