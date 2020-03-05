#include <tabulate/asciidoc_exporter.hpp>
using namespace tabulate;

int main() {
  Table movies;
  movies.add_row({"S/N", "Movie Name", "Director", "Estimated Budget", "Release Date"});
  movies.add_row({"tt1979376", "Toy Story 4", "Josh Cooley", "$200,000,000", "21 June 2019"});
  movies.add_row({"tt3263904", "Sully", "Clint Eastwood", "$60,000,000", "9 September 2016"});
  movies.add_row(
      {"tt1535109", "Captain Phillips", "Paul Greengrass", "$55,000,000", " 11 October 2013"});

  // center align 'Director' column
  movies.column(2).format().font_align(FontAlign::center);

  // right align 'Estimated Budget' column
  movies.column(3).format().font_align(FontAlign::right);

  // right align 'Release Date' column
  movies.column(4).format().font_align(FontAlign::right);

  movies[1][2].format().font_style({FontStyle::bold, FontStyle::italic});
  movies[2][1].format().font_style({FontStyle::italic});

  // Color header cells
  for (size_t i = 0; i < 5; ++i) {
    movies[0][i]
        .format()
        .font_color(Color::white)
        .font_style({FontStyle::bold})
        .background_color(Color::blue);
  }

  AsciiDocExporter exporter;
  exporter.configure().indentation(8);
  auto asciidoc = exporter.dump(movies);

  // tabulate::table
  std::cout << movies << "\n\n";

  // Exported Markdown
  std::cout << asciidoc << std::endl;
}
