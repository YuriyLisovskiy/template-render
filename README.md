# Template Render

### Download and Open

Download as a zip archive or clone a repository:

```
git clone https://github.com/YuriyLisovskiy/TemplateRender.git
```
Move to the project folder:
```
cd TemplateRender
```

### Usage

1. Include `src/include/Header.h` to a file where `TemplateRender::render()` is used.
2. In `src/include/Config.h` file specify the paths `TEMPLATE_DIR` for template search, `ENDPOINT_DIR` for rendered HTML document 
and `MEDIA_DIR` for media files search.

    Default values which are used for testing:
    ```
        TEMPLATE_DIR: "ROOT_DIR/test/templates/"
        ENDPOINT_DIR: "ROOT_DIR/test/"
        MEDIA_DIR: "ROOT_DIR/test/media/"
    ```
3. Create a context object using vector of pairs of keys and values (or do not create if it is not used).
    > \* Keys and values must have `std::string` type, use `TemplateRender::str()` to convert any data to string.
    
    > \* Required an `std::ostringstream` operator for custom data types.
    
    > \* For arrays of objects use `std::vector` container.

    Example:
    ```
        std::vector<std::pair<std::string, std::string>> context = {
            { "first_key", "first_value" },
            { "second_key", "second_value" },
            { "third_key", TemplateRender::str<int>(2017) }
        };
        Context* contextObject = new Context(context);
	```
4. Design a template (check for 'Available syntax' section).
5. In `AppStart.cpp` call `TemplateRender::render()` function and pass arguments:
the first is template name, the second is rendered HTML document name, the third is your context
(if context is not used ignore this argument, default is `nullptr`).

    Example:
    ```
        TemplateRender::render("index.html", "completed.html", contextObject);
    ```
6. Build and run the project.
7. Find rendered HTML document in the `ENDPOINT_DIR` directory that was specified earlier.  

### Available syntax
1. 'For' loop statement tag.

    Example:
    
    ```
        {% for (size_t i = 0; i < 5; i++) %}
            /*loop_body*/
            {{ i }}
            /*loop_body*/
        {% endfor %}
    ```
2. 'Foreach' loop statement tag.

    Example:
    
    ```
        {% for (auto some_var : some_collection) %}
            /*loop_body*/
            {{ some_var }}
            /*loop_body*/
        {% endfor %}
    ```
3. 'If' statement tag.

    Example:

    ```
        {% if (some_var_from_context) %}
            /*condition_body*/
        {% else %}
            /*else_body*/
        {% endif %}
    ```
    ```
        {% if (first_var_from_context <= second_var_from_context) %}
            /*condition_body*/
        {% endif %}
    ```
    > \* Only a comparison of two strings or two numbers is available.
4. Tag for including another html documents.

    Example:

    ```
        {% #include "some_snippet.html" %}
    ```
5. Tag for commenting code in templates.

    Example:

    ```
        {% comment "Comment explanation" %}
            /*Some content to comment on*/
        {% endcomment %}
    ```
    
6. Variables.

    Example:

    ```
        {{ some_var_from_context }}
    ```
7. Static files.

    Example:

    ```
        <img src="{% #static 'some_image_from_context' %}" />
    ```
    ```
        <img src="{% #static 'some_image.png' %}" />
    ```
    
> Note: the project is not tested completely, so, there still can be bugs.

### Authors


* **[Yuriy Lisovskiy](https://github.com/YuriyLisovskiy)** - the majority of the project
* [Yuriy Vasko](https://github.com/YuraVasko)
* [Andrii Vaskiv](https://github.com/AndriiVaskiv)
* [Andriy Dubyk](https://github.com/andrewDubyk)
* [Natalia Pachva](https://github.com/nataliapachva)
* [Oleg Zhuk](https://github.com/NSArray47)
