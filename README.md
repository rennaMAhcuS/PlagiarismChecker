# Plagiarism Checker - DSA Project

A Plagiarism Checker!

This is a course project for the CS293 (IIT Bombay) DSA Lab, 2024.

[**Source**](https://github.com/SuperSat001/CS293-Project-2024) - contains the problem statement and the required files.

## Instructions to use the `Dockerfile`

For the first time, run

```sh
docker build . --tag copycatchers
docker run --interactive --tty --volume .:/home/Loki/plagiarism_checker --name=NP-MOS --network=bridge --hostname=Midgard copycatchers:latest
```

To use the docker container, run

```sh
docker start --attach --interactive NP-MOS
```

for a shorter command, use:

```sh
docker start -ai NP-MOS
```

> [!NOTE]
>
> The password for the user **`Loki`** is `huffman`.

## Instructions to add the formatter:

If not present, create a `.vscode` directory in the project repository, create a new file called `settings.json` and add the following code in it:

> [!IMPORTANT]
>
>  ### `settings.json`
>
> ```json
> {
>   "C_Cpp.clang_format_fallbackStyle": "{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0, AllowShortFunctionsOnASingleLine: All, BreakBeforeBraces: Attach}"
> }
> ```
