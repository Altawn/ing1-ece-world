# Assets Directory

This directory contains all game assets (images and sounds) used in the project.

## Structure

```
assets/
├── images/           # All image files
│   ├── deplacement/  # Movement/displacement sprites
│   ├── pfc/          # Pierre-Feuille-Ciseaux (Rock-Paper-Scissors) game images
│   ├── presentation/ # Presentation and background images
│   ├── snake/        # Snake game images
│   └── *.bmp/*.png   # General game images (splash screens, menus, etc.)
└── sounds/           # Music and sound files
    └── *.mid         # MIDI music files
```

## Image Files

The project currently uses BMP (Bitmap) images, which are uncompressed and take significant disk space. 
Some images have also been converted to PNG format which provides better compression.

### Recommendations for Future Optimization

1. **Convert BMP to PNG**: BMP files are uncompressed. Converting them to PNG can reduce file sizes by 70-90% without quality loss.
   - Tools: GIMP, ImageMagick, or online converters
   - Command example: `convert image.bmp image.png`

2. **Reduce Image Dimensions**: Some background images are quite large (e.g., 1024x768). Consider if smaller sizes would work for the game resolution.

3. **Sprite Sheets**: Multiple small sprites (like animation frames) could be combined into sprite sheets for better performance.

## Sound Files

Currently uses MIDI (.mid) files which are already compact. No optimization needed for now.

## Important Notes

- **Do not delete or modify assets without testing**: Many assets are referenced by hardcoded paths in the source code.
- **Before converting images**: Test that the allegro library can load the new format (BMP is well-supported, PNG may require additional libraries).
- **Backup before batch operations**: Keep originals when performing bulk conversions or optimizations.

## Asset Paths in Code

After this reorganization, asset paths in the code need to reference:
- Images: `assets/images/filename.bmp`
- Sounds: `assets/sounds/filename.mid`
- Subdirectory images: `assets/images/snake/filename.bmp`, etc.

Check the source code and update hardcoded paths if necessary.
