[% IF whole.error %]
[% IF whole.status == 'missing_identifier' %]
<p><em>Please Note:</em> Mandatory field Identifier is missing.</p>
[% ELSIF whole.status == 'missing_branch' %]
<p><em>Please Note:</em> Branch is a mandatory field.</p>
[% ELSIF whole.status == 'invalid_borrower' %]
<p><em>Please Note:</em> The borrower details you entered are invalid.</p>
[% ELSIF whole.status == 'invalid_branch' %]
<p><em>Please Note:</em> The branch you chose is invalid.</p>
[% ELSE %]
<p>Unhandled error</p>
[% END %]
[% END %]

[% IF whole.stage == "form" %]
<form id="create_form" method="POST" action=[% here %]>
  [% INCLUDE 'csrf-token.inc' %]
  <fieldset class="rows">
    <legend>Tiedot</legend>
    <ol id="general-freeform-fields">
      <li>
        <label class="required" for="type">Tyyppi:</label>
        <select name="type" id="type">
          <option value=""/>
          [% IF whole.value.other.type.lower == "article" %]
          <option value="article" selected="selected">Artikkeli</option>
          [% ELSE %]
          <option value="article">Artikkeli</option>
          [% END %]
          [% IF whole.value.other.type.lower == "resource" %]
          <option value="resource" selected="selected">CD</option>
          [% ELSE %]
          <option value="resource">CD</option>
          [% END %]
          [% IF whole.value.other.type.lower == "journal" %]
          <option value="journal" selected="selected">Kausijulkaisu</option>
          [% ELSE %]
          <option value="journal">Kausijulkaisu</option>
          [% END %]
          [% IF whole.value.other.type.lower == "book" %]
          <option value="book" selected="selected">Kirja</option>
          [% ELSE %]
          <option value="book">Kirja</option>
          [% END %]
          [% IF whole.value.other.type.lower == "dvd" %]
          <option value="dvd" selected="selected">Videotallenne</option>
          [% ELSE %]
          <option value="dvd">Videotallenne</option>
          [% END %]
          [% IF whole.value.other.type.lower == "other" %]
          <option value="other" selected="selected">Muu</option>
          [% ELSE %]
          <option value="other">Muu</option>
          [% END %]
        </select>
      </li>
    </ol>
  </fieldset>
  [% cwd = whole.cwd %]
  [% type = whole.value.other.type %]
  [% IF type %]
      [% INCLUDE "${cwd}/shared-includes/forms/${type}.inc" %]
  [% END %]
  [% INCLUDE "${cwd}/shared-includes/custom_fields.inc" %]
  <fieldset class="rows">
    <legend>Patron options</legend>
    <ol>
      <li>
        <label class="required" for="branchcode">Destination library:</label>
        <select id="branchcode" name="branchcode">
          <option value="" />
          [% FOREACH branch IN branches %]
            [% IF whole.value.other.branchcode && branch.branchcode == whole.value.other.branchcode %]
            <option value="[% branch.branchcode %]" selected>
              [% branch.branchname %]
            </option>
            [% ELSE %]
            <option value="[% branch.branchcode %]">
              [% branch.branchname %]
            </option>
            [% END %]
          [% END %]
        </select>
      </li>
    </ol>
  </fieldset>

  <fieldset class="action">
    <input id="ill-submit" class="btn btn-default" type="submit" value="Luo kaukolainapyyntö"/>
    <a class="cancel" href="/cgi-bin/koha/opac-illrequests.pl">Peruuta</a>
  </fieldset>
  <input type="hidden" name="op" value="cud-create" />
  <input type="hidden" name="stage" value="form" />
  <input type="hidden" name="backend" value="FreeForm" />
</form>

[% ELSE %]
<p>Unknown stage.  This should not have happened.

[% END %]
[% BLOCK backend_jsinclude %]
<script type="text/javascript">
    // <![CDATA[]
    [% INCLUDE "${cwd}/shared-includes/shared.js" %]
    // ]]>
</script>
[% END %]
