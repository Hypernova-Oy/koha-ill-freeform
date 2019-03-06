[% IF whole.error %]
[% IF whole.status == 'missing_title' %]
<p><em>Please Note:</em> Mandatory field Title is missing.</p>
[% ELSIF whole.status == 'missing_type' %]
<p><em>Please Note:</em> Mandatory field Type is missing.</p>
[% ELSIF whole.status == 'missing_author' %]
<p><em>Please Note:</em> Mandatory field Author is missing.</p>
[% ELSE %]
<p>Unhandled error</p>
[% END %]
[% END %]

<h2>Edit a manual ILL request</h2>
<form method="POST" action=[% here %]>
  <fieldset class="rows">
    <legend>General details</legend>
    <ol id="general-freeform-fields">
      <li>
        <label class="required" for="type">Type:</label>
        <select name="type" id="type">
          <option value=""/>
          [% IF whole.value.other.type.lower == "book" %]
          <option value="book" selected="selected">Book</option>
          [% ELSE %]
          <option value="book">Book</option>
          [% END %]
          [% IF whole.value.other.type.lower == "article" %]
          <option value="article" selected="selected">Article</option>
          [% ELSE %]
          <option value="article">Article</option>
          [% END %]
          [% IF whole.value.other.type.lower == "journal" %]
          <option value="journal" selected="selected">Journal</option>
          [% ELSE %]
          <option value="journal">Journal</option>
          [% END %]
          [% IF whole.value.other.type.lower == "other" %]
          <option value="other" selected="selected">Other</option>
          [% ELSE %]
          <option value="other">Other</option>
          [% END %]
        </select>
      </li>
    </ol>
  </fieldset>
  <fieldset class="rows">
    <legend>Publication details</legend>
    <input name="stage" id="stage" value="form" type="hidden"/>
    <input name="method" id="method" value="edititem" type="hidden"/>
    <input name="backend" id="method" value="FreeForm" type="hidden"/>
    <input name="illrequest_id" id="illrequest_id" value="[% whole.value.request.id %]" type="hidden"/>
    <ol id="publication-freeform-fields">
      <li>
        <label class="required" for="title">Publication title:</label>
        <input type="text" name="title" id="title" value="[% whole.value.other.title %]" />
      </li>
      <li>
        <label for="author">Author / editor:</label>
        <input type="text" name="author" id="author" value="[% whole.value.other.author %]" />
      </li>
      <li>
        <label for="year">Year:</label>
        <input type="text" name="year" id="year" value="[% whole.value.other.year %]" />
      </li>
      <li>
        <label for="volume">Volume:</label>
        <input type="text" name="volume" id="volume" value="[% whole.value.other.volume %]" />
      </li>
      <li>
        <label for="part_edition">Part / edition:</label>
        <input type="text" name="part_edition" id="part_edition" value="[% whole.value.other.part_edition %]" />
      </li>
      <li>
        <label for="isbn">ISBN:</label>
        <input type="text" name="isbn" id="isbn" value="[% whole.value.other.isbn %]" />
      </li>
      <li>
        <label for="issn">ISSN:</label>
        <input type="text" name="issn" id="issn" value="[% whole.value.other.issn %]" />
      </li>
    </ol>
  </fieldset>
  <fieldset class="rows">
    <legend>Article / chapter / part details</legend>
    <ol id="article-freeform-fields">
      <li>
        <label for="article_title">Title:</label>
        <input type="text" name="article_title" id="article_title" value="[% whole.value.other.article_title %]" />
      </li>
      <li>
        <label for="article_author">Author:</label>
        <input type="text" name="article_author" id="article_author" value="[% whole.value.other.article_author %]" />
      </li>
      <li>
        <label for="article_pages">Pages:</label>
        <input type="text" name="article_pages" id="article_pages" value="[% whole.value.other.article_pages %]" />
      </li>
    </ol>
  </fieldset>
  <fieldset class="rows">
    <legend>Custom fields</legend>
    <ol id="freeform-fields">
      [% custom_keys = whole.value.other.custom_key_del.split('\t') %]
      [% custom_values = whole.value.other.custom_value_del.split('\t') %]
      [% i = 0 %]
      [% FOR key IN custom_keys %]
      <li class="form-horizontal">
        <input type="text" class="custom-name" name="custom_key" value="[% key %]"><input type="text" name="custom_value" id="custom-value" value="[% custom_values.$i %]">
        <button value="[% i %]" name="custom_delete" type="submit" class="btn btn-danger btn-sm delete-new-field">
            <span class="fa fa-delete"></span>Delete
        </button></li>
      </li>
      [% i = i + 1 %]
      [% END %]
    </ol>
    <button type="button" id="add-new-fields" class="btn btn-default">
      <span class="fa fa-plus"></span>
      Add new field
    </button> 
  </fieldset>
  <fieldset class="action">
    <input type="submit" value="Update"/>
    <a class="cancel" href="/cgi-bin/koha/ill/ill-requests.pl">Cancel</a>
  </fieldset>
</form>
[% BLOCK backend_jsinclude %]
<script type="text/javascript">
    // <![CDATA[]
        document.addEventListener("DOMContentLoaded", function() {
            $('#add-new-fields').click(function(e) {
                e.preventDefault();
                var row = '<li class="form-horizontal">' +
                    '<input type="text" class="custom-name" name="custom_key">' +
                    '<input type="text" id="custom-value" name="custom_value"> '+
                    '<button type="button" class="btn btn-danger btn-sm ' +
                    'delete-new-field">' +
                    '<span class="fa fa-delete">' +
                    '</span>Delete</button></li>';
                $('#freeform-fields').append(row);
            });
            $('#freeform-fields').on('click', '.delete-new-field',
                function(event) {
                    event.preventDefault();
                    $(event.target).parent().remove();
                }
            );
        });
    // ]]>
</script>
[% END %]