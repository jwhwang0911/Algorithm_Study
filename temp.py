from PIL import Image
import os


def invert_color(color):
    return 255 - color

def invert_colors_in_image(input_path, output_path):
    # Open the image
    image = Image.open(input_path)
    
    # Convert image to RGB mode
    image_rgb = image.convert("RGB")
    
    # Get image size
    width, height = image.size
    
    # Create a new blank image with the same size
    inverted_image = Image.new("RGB", (width, height))
    
    # Iterate through each pixel and invert the color
    threshold = 70
    for x in range(width):
        for y in range(height):
            r, g, b = image_rgb.getpixel((x, y))
            # if r <= threshold and g <= threshold and b <= threshold:
            #     inverted_r = invert_color(r)
            #     inverted_g = invert_color(g)
            #     inverted_b = invert_color(b)
            # elif r >= 255-threshold and g >= 255-threshold and b >= 255-threshold:
            #     inverted_r = invert_color(r)
            #     inverted_g = invert_color(g)
            #     inverted_b = invert_color(b)
            # else:
            #     inverted_r = r
            #     inverted_b = b
            #     inverted_g = g
            inverted_r, inverted_g, inverted_b = invert_color(r), invert_color(g), invert_color(b)
            
            inverted_image.putpixel((x, y), (inverted_r, inverted_g, inverted_b))
    
    # Save the inverted image
    inverted_image.save(output_path)
    
    # Close the images
    image.close()
    inverted_image.close()

# 사용 예시

for root, dirs, files in os.walk("E:\Algorithm_Study\image_folder"):
    for file in files:
        input_image_path = os.path.join(root, file)
        output_image_path = os.path.join("E:\Algorithm_Study\output_folder", file)
        invert_colors_in_image(input_image_path, output_image_path)


# input_image_path = "E:\Algorithm_Study\image_folder\Part 1 BS4219 Introduction to Cancer - The Biology and Genetics of Cells and Organism (1)_1.jpg"
# output_image_path = "output_image.jpg"
# invert_colors_in_image(input_image_path, output_image_path)
